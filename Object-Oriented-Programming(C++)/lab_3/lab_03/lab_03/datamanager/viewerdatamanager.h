#ifndef LAB_03_VIEWERDATAMANAGER_H
#define LAB_03_VIEWERDATAMANAGER_H


#include <command/iappcommand.h>
#include <ui/scene/sceneobjectcomposite.h>
#include <ui/camera/camera.h>
#include <controller/icommandexecute.h>

#include <memory>
#include <map>
#include <ui/drawermediator.h>

class ViewerDataManager final {
public:
    ViewerDataManager() : _activeCameraId(0) {};
    ~ViewerDataManager();

    void addCommand(unsigned id, std::shared_ptr<IAppCommand> command);
    std::shared_ptr<IAppCommand>& getCommand(unsigned id);

    void addExecutor(unsigned id, std::shared_ptr<ICommandExecutor> executor);
    std::shared_ptr<ICommandExecutor>& getExecutor(unsigned id);

    void addComposite(unsigned id, std::shared_ptr<SceneObjectComposite> composite);
    void removeComposite(unsigned id);
    std::shared_ptr<SceneObjectComposite>& getComposite(unsigned id);
    std::map<unsigned, std::shared_ptr<SceneObjectComposite>>& getComposites();

    void addModel(unsigned id, std::shared_ptr<IModel> model);
    std::shared_ptr<IModel> getModel(unsigned id);
    std::map<unsigned, std::shared_ptr<IModel>> getModels();
    void removeModel(unsigned id);

    void addCamera(unsigned id, std::shared_ptr<Camera> camera);
    std::map<unsigned, std::shared_ptr<Camera>>& getCameras();
    void setActiveCamera(unsigned id);
    std::shared_ptr<Camera>& getActiveCamera();

    void setDrawerMediator(std::shared_ptr<DrawerMediator> mediator);
    std::shared_ptr<DrawerMediator> getDrawerMediator();

private:
    unsigned _activeCameraId { 0 };
    std::map<unsigned, std::shared_ptr<IAppCommand>> _commands;
    std::map<unsigned, std::shared_ptr<ICommandExecutor>> _executors;
    std::map<unsigned, std::shared_ptr<SceneObjectComposite>> _composites;
    std::map<unsigned, std::shared_ptr<IModel>> _models;
    std::map<unsigned, std::shared_ptr<Camera>> _cameras;
    std::shared_ptr<DrawerMediator> _drawerMediator { nullptr };
};


#endif
