#include "transfercommand.h"

TransferCommand::TransferCommand(std::shared_ptr<SceneObjectComposite> &model) : IAppCommand(model) {}

void TransferCommand::execute(IAppCommand::Argument arg) {
    _composite->transfer(arg.motion.data.transfer_act.dx, arg.motion.data.transfer_act.dy, arg.motion.data.transfer_act.dz);
}
