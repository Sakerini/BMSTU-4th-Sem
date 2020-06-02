#include "viewerdatamanager.h"

ViewerDataManager::~ViewerDataManager() {
}

void ViewerDataManager::addCommand(unsigned id, std::shared_ptr<IAppCommand> command) {
    _commands[id] = std::move(command);
}
std::shared_ptr<IAppCommand>& ViewerDataManager::getCommand(unsigned id) {
    return _commands[id];
}

void ViewerDataManager::addExecutor(unsigned id, std::shared_ptr<ICommandExecutor> executor) {
    _executors[id] = std::move(executor);
}

std::shared_ptr<ICommandExecutor>& ViewerDataManager::getExecutor(unsigned id) {
    return _executors[id];
}

void ViewerDataManager::addComposite(unsigned id, std::shared_ptr<SceneObjectComposite> composite) {
    _composites[id] = std::move(composite);
}
void ViewerDataManager::removeComposite(unsigned id) {
    _composites.erase(id);
}

std::shared_ptr<SceneObjectComposite>& ViewerDataManager::getComposite(unsigned id) {
    return _composites[id];
}

std::map<unsigned, std::shared_ptr<SceneObjectComposite>>& ViewerDataManager::getComposites() {
    return _composites;
}

void ViewerDataManager::addModel(unsigned id, std::shared_ptr<IModel> model) {
    _models[id] = std::move(model);
}

std::shared_ptr<IModel> ViewerDataManager::getModel(unsigned id) {
    return _models[id];
}
std::map<unsigned, std::shared_ptr<IModel>> ViewerDataManager::getModels() {
    return _models;
}

void ViewerDataManager::removeModel(unsigned id) {
    _models.erase(id);
}

void ViewerDataManager::addCamera(unsigned id, std::shared_ptr<Camera> camera) {
    _cameras[id] = std::move(camera);
}
std::map<unsigned, std::shared_ptr<Camera>>& ViewerDataManager::getCameras() {
    return _cameras;
}
void ViewerDataManager::setActiveCamera(unsigned id) {
    _activeCameraId = id;
}

std::shared_ptr<Camera>& ViewerDataManager::getActiveCamera() {
    return _cameras[_activeCameraId];
}

void ViewerDataManager::setDrawerMediator(std::shared_ptr<DrawerMediator> mediator) {
    _drawerMediator = std::move(mediator);
}

std::shared_ptr<DrawerMediator> ViewerDataManager::getDrawerMediator() {
    return _drawerMediator;
}
