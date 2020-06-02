#include <factory/model3dfactory.h>
#include "loadimplementater.h"
#include <memory>
#include <geometry/model/model3d.h>
#include <geometry/model/builder/3dmodelBuilder.h>
#include <geometry/model/builder/director.h>

void LoadModelImplementer::execute(ViewerDataManager &dm, IAppCommand::Argument arg, MainWindow::CMD cmd) {
    //std::shared_ptr<Director> director(new ModelBuilder3d(arg.load_act.file));
    auto builder = new ModelBuilder3d(arg.load_act.file);
    auto newModel = std::shared_ptr<Model3d> (builder->getResult());
   // auto newModel = director->make();
    //auto newModel = std::shared_ptr<Model3d>(Model3dFactory::getInstance()->createModel());
    //newModel->load(arg.load_act.file);

    auto newComposite = std::shared_ptr<SceneObjectComposite>(Model3dFactory::getInstance()->createSceneObjectComposite());
    newComposite->add(newModel);

    dm.addComposite(arg.load_act.id, newComposite);
    dm.addModel(arg.load_act.id, newModel);
}