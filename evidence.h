#ifndef PROJECT_GROUP_HHH_EVIDENCE_H
#define PROJECT_GROUP_HHH_EVIDENCE_H


class Evidence 
{
    private:
        string itemId;
        string details;
    public:
        Evidence();
        Evidence(string itemId,string details);
        void displayInfo();
        json toJson();
        static Evidence fromJson(const json& j);
};


#endif //PROJECT_GROUP_HHH_EVIDENCE_H
