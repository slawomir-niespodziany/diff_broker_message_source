#include <MessageSource.h>
#include <iostream>

using namespace std::string_literals;

MessageSource::MessageSource(ILink &linkPrimary, ILink &linkBackup)
    : linkPrimary_{linkPrimary}, linkBackup_{linkBackup}, content_{config<std::string>("content"s)}, count_{config<std::size_t>("count"s)} {   // configuration from json
    std::cout << type() << "{"s << id() << "}"s << std::endl;                                                                                  // log construction
}
MessageSource::~MessageSource() { std::cout << "~"s << type() << "{"s << id() << "}"s << std::endl; }

bool MessageSource::finished() { return (count_ <= n_); }

void MessageSource::process() {
    if (!finished()) {
        std::string message = "from "s + id() + ", #"s + std::to_string(n_) + ", \""s + content_ + "\""s;
        n_++;

        if (!linkPrimary_.send(message)) {
            linkBackup_.send(message);
        }
    }
}
