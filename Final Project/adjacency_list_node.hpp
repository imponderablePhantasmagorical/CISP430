class AdjacencyListNode {
    public:
        AdjacencyListNode(int destination, int weight);
        AdjacencyListNode *next;
        int get_destination();
        int get_weight();
    private:
        int destination;
        int weight;
};
