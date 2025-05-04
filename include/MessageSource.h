#pragma once

#include <ILink.h>
#include <IProcessable.h>
#include <diff/Component.h>

class MessageSource : public diff::Component<MessageSource, diff::as<IProcessable>> {
public:
    MessageSource(ILink &linkPrimary, ILink &linkBackup);
    virtual ~MessageSource();

    bool finished() override;
    void process() override;

private:
    ILink &linkPrimary_;
    ILink &linkBackup_;

    const std::string content_;
    const std::size_t count_;
    std::size_t n_{0u};
};
