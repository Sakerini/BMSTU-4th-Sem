#include "scalecommand.h"

ScaleCommand::ScaleCommand(std::shared_ptr<SceneObjectComposite> &model) : IAppCommand(model) {}

void ScaleCommand::execute(IAppCommand::Argument arg) {
    _composite->scale(arg.motion.data.scale_act.k);
}
