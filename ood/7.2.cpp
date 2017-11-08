#include <string>
#include <memory>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>

struct Call {
    std::string caller;
    size_t difficulty;
};

class CallHandler {
private:
    size_t difficulty_level_;
    bool is_free_;
    std::string name_;
public:
    CallHandler(const size_t difficulty_level, const std::string& name)
        : difficulty_level_(difficulty_level), is_free_(true), name_(name)
    {}

    size_t GetDifficultyLevel() const {
        return difficulty_level_;
    }
    bool IsAbleToHandle(const Call& call) const {
        return difficulty_level_ > call.difficulty;
    }
    void StartCall() {
        is_free_ = false;
    }
    void StopCall() {
        is_free_ = true;
    }
    bool IsFree() const {
        return is_free_;
    }
    std::string GetName() const {
        return name_;
    }
    virtual ~CallHandler(){}
};


class Fresher : public CallHandler {
public:
    using CallHandler::CallHandler;
};

const size_t PROJECT_MANAGER_DIFFICULTY_LEVEL = 50;
const std::string PROJECT_MANAGER_NAME = "alex";

class ProjectManager : public CallHandler {
public:
    static ProjectManager& GetInstance() {
        static ProjectManager project_manager;
        return project_manager;
    }
private:
    ProjectManager()
        : CallHandler(PROJECT_MANAGER_DIFFICULTY_LEVEL, PROJECT_MANAGER_NAME)
    {}

    ProjectManager(const ProjectManager&) = delete;
    ProjectManager& operator=(const ProjectManager&) = delete;
    ~ProjectManager()
    {}
};

const size_t TECHNICAL_LEADER_DIFFICULTY_LEVEL = 1000;
const std::string TECHNICAL_LEADER_NAME = "john";

class TechnicalLeader: public CallHandler {
public:
    static TechnicalLeader& GetInstance() {
        static TechnicalLeader technical_leader;
        return technical_leader;
    }
private:
    TechnicalLeader()
        : CallHandler(TECHNICAL_LEADER_DIFFICULTY_LEVEL, TECHNICAL_LEADER_NAME)
    {}

    TechnicalLeader(const TechnicalLeader&) = delete;
    TechnicalLeader& operator=(const TechnicalLeader&) = delete;
    ~TechnicalLeader()
    {}
};

class CallDistributor {
private:
    std::unordered_map<std::string, CallHandler*> call_handlers_;
    std::map<size_t, CallHandler*> ready_call_freshers_;
public:
    CallDistributor(
        const std::vector<std::shared_ptr<CallHandler>>& freshers
    )
    {
        for (std::shared_ptr<CallHandler> fresher: freshers) {
            ready_call_freshers_[fresher->GetDifficultyLevel()] = fresher.get();
        }
    }
    CallHandler* GetCallHandler(const Call& call) {
        auto it = ready_call_freshers_.lower_bound(call.difficulty);
        CallHandler* call_handler;
        if (it == ready_call_freshers_.end()) {
            if (TechnicalLeader::GetInstance().IsFree() && TechnicalLeader::GetInstance().IsAbleToHandle(call)) {
                call_handler = &TechnicalLeader::GetInstance();
            } else {
                call_handler = &ProjectManager::GetInstance();
            }
        } else {
            call_handler = it->second;
            ready_call_freshers_.erase(it);
        }
        call_handler->StartCall();
        std::cout << "Call from " << call.caller << " will be served by " << call_handler->GetName() << "\n";
        call_handlers_[call.caller] = call_handler;
        return call_handler;
    }
    void FinishCall(const Call& call) {
        auto call_handler = call_handlers_[call.caller];
        call_handler->StopCall();
        if (dynamic_cast<Fresher*>(call_handler)) {
            ready_call_freshers_[call_handler->GetDifficultyLevel()] = call_handler;
        }
        std::cout << "Call from " << call.caller << " is finished by " << call_handler->GetName() << "\n";
        call_handlers_.erase(call.caller);
    }
};
int main() {
    std::shared_ptr<CallHandler> first_fresher = std::make_shared<Fresher>(1, "alexa");
    std::shared_ptr<CallHandler> second_fresher = std::make_shared<Fresher>(10, "kate");
    CallDistributor call_distributor({first_fresher, second_fresher});
    Call first_call({"oleg", 2});
    call_distributor.GetCallHandler(first_call);
    Call second_call({"stacy", 2});
    call_distributor.GetCallHandler(second_call);
    Call third_call({"denis", 4});
    call_distributor.GetCallHandler(third_call);
    call_distributor.FinishCall(first_call);
    call_distributor.FinishCall(second_call);
    call_distributor.FinishCall(third_call);
    return 0;
}
