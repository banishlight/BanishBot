


#include <vector>

class BuildOrder {

    private:
        void generateTestBuild();

    public:
        BuildOrder();
        void getBuild();

};

class BuildNode {
    std::vector<BuildNode> children;
    private:

    public:
        BuildNode();
        BuildNode(int nChildren);

};