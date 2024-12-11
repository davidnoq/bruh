#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <string>
#include <utility> // For std::pair

class InMemoryDatabase {
private:
    std::unordered_map<std::string, int> data; // Main database state
    std::unordered_map<std::string, int> transaction; // Transaction state
    bool transactionInProgress = false;

public:
    void begin_transaction() {
        if (transactionInProgress) {
            throw std::runtime_error("A transaction is already in progress.");
        }
        transaction.clear();
        transactionInProgress = true;
    }

    void put(const std::string& key, int value) {
        if (!transactionInProgress) {
            throw std::runtime_error("Cannot call put(key, value) outside of a transaction.");
        }
        transaction[key] = value;
    }

    std::pair<bool, int> get(const std::string& key) {
        if (transactionInProgress && transaction.find(key) != transaction.end()) {
            return {true, transaction[key]};
        }
        auto it = data.find(key);
        if (it != data.end()) {
            return {true, it->second};
        }
        return {false, 0}; // Key does not exist
    }

    void commit() {
        if (!transactionInProgress) {
            throw std::runtime_error("No transaction to commit.");
        }

        for (const auto& [key, value] : transaction) {
            data[key] = value;
        }

        transactionInProgress = false;
        transaction.clear();
    }

    void rollback() {
        if (!transactionInProgress) {
            throw std::runtime_error("No transaction to rollback.");
        }

        transactionInProgress = false;
        transaction.clear();
    }
};


int main() {
    InMemoryDatabase db;

    try {
        db.put("A", 5); //set key "A" outside of a transaction
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl; 
    }

    db.begin_transaction();
    db.put("A", 5); //key "A" with value 5 within a transaction
    auto result = db.get("A");
    std::cout << "Value of A before commit: " << (result.first ? std::to_string(result.second) : "null") << std::endl;

    db.put("A", 6); //key "A" to value 6 within the same transaction
    db.commit();
    result = db.get("A");
    std::cout << "Value of A after commit: " << (result.first ? std::to_string(result.second) : "null") << std::endl;

    try {
        db.commit(); //commit without an active transaction
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        db.rollback(); //rollback without an active transaction
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    result = db.get("B");
    std::cout << "Value of B (not yet set): " << (result.first ? std::to_string(result.second) : "null") << std::endl;

    db.begin_transaction();
    db.put("B", 10); //adding key "B" with value 10 within a transaction
    db.rollback(); //rolling back the transaction
    result = db.get("B");
    std::cout << "Value of B after rollback: " << (result.first ? std::to_string(result.second) : "null") << std::endl;

    return 0;
}