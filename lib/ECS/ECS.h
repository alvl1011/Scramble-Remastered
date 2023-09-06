#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID _getComponentTypeID() {

	static ComponentID lastID = 0u;
	return lastID++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept {

	static_assert (std::is_base_of<Component, T>::value, "");
	static ComponentID typeID = _getComponentTypeID();
	return typeID;
}


constexpr std::size_t max_components = 32;
constexpr std::size_t max_groups = 32;

using ComponentBitSet = std::bitset<max_components>;
using GroupBitSet = std::bitset<max_groups>;

using ComponentArray = std::array<Component*, max_components>;

class Component {
	
public:

	Entity* entity;

	virtual ~Component() {}

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}
};

class Entity {

private:

	Manager& manager;

	bool active = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray component_array;
	ComponentBitSet component_bit_set;
	GroupBitSet group_bit_set;

public:
	
	Entity(Manager& mManager) : manager(mManager) { }

	void update() {

		for (auto& component : components) {
			component->update();
		}
	}

	void draw() {

		for (auto& component : components) {
			component->draw();
		}
	}

	void destroy() {
		active = false;
	}

	bool isActive() const {
		return active;
	}

	void isActive(bool value) {
		active = value;
	}

	bool hasGroup(Group mGroup) {
		return group_bit_set[mGroup];
	}

	void addGroup(Group mGroup);
	void deleteGroup(Group mGroup);

	template <typename T> bool hasComponent() const {
		return component_bit_set[getComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs) {

		T* component(new T(std::forward<TArgs>(mArgs)...));
		component->entity = this;
		std::unique_ptr<Component> uPtr{ component };
		components.emplace_back(std::move(uPtr));

		component_array[getComponentTypeID<T>()] = component;
		component_bit_set[getComponentTypeID<T>()] = true;

		component->init();
		return *component;
	}

	template <typename T> T& getComponent() const {

		auto ptr(component_array[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}
};

class Manager {

private:

	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, max_groups> grouped_entities;

public:

	void update() {
		for (auto& entity : entities) entity->update();
	}

	void draw() {
		for (auto& entity : entities) entity->draw();
	}

	void refresh() {

		for (auto i(0u); i < max_groups; i++) {
			auto& v(grouped_entities[i]);
			v.erase(std::remove_if(std::begin(v), std::end(v), [i](Entity* mEntity) {
				return !mEntity->isActive() || !mEntity->hasGroup(i);
				}), std::end(v));
		}

		entities.erase(std::remove_if(std::begin(entities), std::end(entities), 
			[](const std::unique_ptr<Entity>& mEntity) {
				return !mEntity->isActive();
			}), std::end(entities));
	}

	void AddToGroup(Entity* mEntity, Group mGroup) {
		grouped_entities[mGroup].emplace_back(mEntity);
	}

	void DeleteFromGroup(Entity* mEntity, Group mGroup) {
		auto& v(grouped_entities[mGroup]);
		v.erase(std::remove_if(std::begin(v), std::end(v), [mGroup](Entity* mEntity) {
			return !mEntity->isActive() || !mEntity->hasGroup(mGroup);
			}), std::end(v));
	}

	std::vector<Entity*>& getGroup(Group mGroup) {
		return grouped_entities[mGroup];
	}

	Entity& addEntity() {
		Entity* entity = new Entity(*this);
		std::unique_ptr<Entity> uPtr{ entity };
		entities.emplace_back(std::move(uPtr));
		return *entity;
	}
};