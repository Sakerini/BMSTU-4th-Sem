#include "rotatecommand.h"

RotateCommand::RotateCommand(std::shared_ptr<SceneObjectComposite> &model) : IAppCommand(model) {}

void RotateCommand::execute(IAppCommand::Argument arg) {
    _composite->rotate(arg.motion.data.rotate_act.alpha, arg.motion.data.rotate_act.beta, arg.motion.data.rotate_act.gamma);
}
