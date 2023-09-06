
#include "ECS.h"

void Entity::addGroup(Group mGroup) {
	group_bit_set[mGroup] = true;
	manager.AddToGroup(this, mGroup);
}

void Entity::deleteGroup(Group mGroup) {
	group_bit_set[mGroup] = false;
	manager.DeleteFromGroup(this, mGroup);
}