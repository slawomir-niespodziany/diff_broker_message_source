#include <MessageSource.h>
#include <diff/FactoryRegisterer.h>

namespace {
diff::FactoryRegisterer<MessageSource> g_registerer;
}
