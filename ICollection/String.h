#ifndef STRING_H
#define STRING_H

#include "interfaces/ICollectible.h"
#include "interfaces/OrderedKey.h"

class String : public ICollectible, public OrderedKey
{
private:
    char *s;

public:
    String(const char *s = "");
    virtual ~String();
    const char *getValue() const;
    ComparisonRes compare(OrderedKey *k) const;
};

#endif /*_STRING_H */
