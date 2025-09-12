#ifndef GUEST_H
#define GUEST_H

#include <string>

class Guest {
private:
    int id;
    std::string name;
    std::string phone;

public:
    Guest(int id, const std::string& n, const std::string& ph);

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getPhone() const { return phone; }

    void setName(const std::string& n) { name = n; }
    void setPhone(const std::string& ph) { phone = ph; }

    void print() const;
};

#endif
