#include <MessageSource.h>
#include <gtest/gtest.h>

using namespace std::string_literals;

class LinkMock : public ILink {
public:
    bool send(const std::string &message) override {
        count_++;
        return true;
    }

    std::size_t getCount() { return count_; }

private:
    std::size_t count_{0u};
};

TEST(TestMessageSource, SendOneMessage) {
    LinkMock link;
    MessageSource messageSource = diff::Instantiator<MessageSource>("testId"s)   //
                                      .config<std::size_t>("count"s, 1u)
                                      .config<std::string>("content"s, "testContent1"s)
                                      .make_instance(link, link);

    while (!messageSource.finished()) {
        messageSource.process();
    }

    EXPECT_EQ(1u, link.getCount());
}

TEST(TestMessageSource, SendTwoMessages) {
    LinkMock link;
    MessageSource messageSource = diff::Instantiator<MessageSource>("testId"s)   //
                                      .config<std::size_t>("count"s, 2u)
                                      .config<std::string>("content"s, "testContent2"s)
                                      .make_instance(link, link);

    while (!messageSource.finished()) {
        messageSource.process();
    }

    EXPECT_EQ(2u, link.getCount());
}