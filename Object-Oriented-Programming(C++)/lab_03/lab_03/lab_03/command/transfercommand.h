#ifndef LAB_03_TRANSFERCOMMAND_H
#define LAB_03_TRANSFERCOMMAND_H

#include "iappcommand.h"

class TransferCommand final : public IAppCommand {
public:
    TransferCommand() {};
    explicit TransferCommand(std::shared_ptr<SceneObjectComposite> &model);

    void execute(Argument arg) override;
};

#endif
