#include "runtime/function/scene/entity.h"
#include "runtime/function/scene/components.h"

namespace Toy2D {
    Entity::Entity(entt::entity entity_handle, Scene* scene) :
        m_entity_handle(entity_handle), m_parent_scene(scene) {
    }

    std::string Entity::getName() {
        return getComponent<NameComponent>().name;
    }

    void Entity::setName(std::string_view name) {
        getComponent<NameComponent>().name = name.empty() ? "UnNamed_Entity" : std::string(name);
    }

    void Entity::remove() {
        addComponent<RemovedMarkComponent>();
    }

} // namespace Toy2D