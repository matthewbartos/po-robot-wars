#ifndef ACTION_H
#define ACTION_H

namespace logic {
    class game;
}

namespace robots {
    class robot;
}

namespace actions {
    
    class actionfactory;
    
    class action {
    protected:
        robots::robot *object;
        virtual void executeaction() = 0;
        void setobject(robots::robot *object);
    public:
        virtual bool robotiscapabletoperformthisaction() = 0;
        virtual bool verifyparameters();
        
        friend class actionfactory;
        friend class logic::game;
    };
}

#endif
