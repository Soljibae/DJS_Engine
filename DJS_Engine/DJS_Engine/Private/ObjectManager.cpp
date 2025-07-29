#include "ObjectManager.h"
#include "DJS_ENGINE.h"
#include "GameState.h"

void ObjectManager::InitAll()
{
	for (const auto& obj : objects)
	{
		obj->Init();
	}
	for (const auto& obj : objects)
	{
		obj->LateInit();
	}
}

void ObjectManager::UpdateAll()
{
	for (const auto& obj : objects)
	{
		obj->Update();
	}
	for (const auto& obj : objects)
	{
		obj->LateUpdate();
	}
}

void ObjectManager::ExitAll()
{
	for (const auto& obj : objects)
	{
		obj->Exit();
	}
}

void ObjectManager::AddObjectToList(std::unique_ptr<GameObject> object)
{
	objects.push_back(std::move(object));
}