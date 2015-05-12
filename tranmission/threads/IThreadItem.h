//
// Created by adrian on 11.05.15.
//

#ifndef IRC_ITHREADITEM_H
#define IRC_ITHREADITEM_H


class IThreadItem {
public:
    virtual void wait() = 0;
    virtual void start() = 0;
};


#endif //IRC_ITHREADITEM_H
