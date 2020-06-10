#ifndef LAB_03_ROTATECOMMAND_H
#define LAB_03_ROTATECOMMAND_H

#include "iappcommand.h"

class RotateCommand final : public IAppCommand {
public:
    RotateCommand() {};
    explicit RotateCommand(std::shared_ptr<SceneObjectComposite> &model);

    void execute(Argument arg) override;
};


#endif
