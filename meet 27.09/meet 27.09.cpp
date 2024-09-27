#include <iostream>
#include <Windows.h>
#include <string>


class ZooHotel 
{
public:

    void AddCat(Cat& newCat) {
        if (!cats_) //cats_==nullptr
        {
        
            countOfCats_ += 1;
            cats_ = new Cat[countOfCats_]{};
            cats_[countOfCats_ - 1] = newCat;
        
        }
        else
        {
            auto tmp = new Cat[countOfCats_ + 1]{};
            for (int i = 0; i < countOfCats_; i++)
            {
                tmp[i] = cats_[i];
                tmp[countOfCats_] = newCat;
                countOfCats_ += 1;
                std::swap(tmp, cats_);
                delete[] tmp;
            }
        }

    }


    void KickOut(int i)
    {
        if (countOfCats_ == 1)
        {
            delete[]cats_;
            cats_ = nullptr;
            countOfCats_ = 0;
            return;
        }
        
        if (countOfCats_)
        {
            auto tmp = new Cat[countOfCats_ - 1]{};
            for (int j = 0; j < i; j++)
            {
                tmp[j] = cats_[j];

            }
            for (int j = i+1; j < countOfCats_; j++)
            {
                tmp[j-1] = cats_[j];

            }
            std::swap(tmp, cats_);
            delete[]tmp;
            countOfCats_ -= 1;
        }
    
    
    }


    ~ZooHotel()
    {
        if (cats_)
        {
            delete[] cats_;
        }
    }

    int size()const {
        return countOfCats_;
    }

    const Cat& operator[](int i)const
    {
        return cats_[i];
    }



private:
    std::string name_;
    Cat* cats_;
    int countOfCats_;


};

class Cat {
public:
    Cat() :name_("MaminaRadost"), age_(13), gender_("Boy") {}
    Cat(std::string name, int age, std::string gender) :
        name_(name),
        age_(age),
        gender_(gender)
    {}

    std::string  GetName() const
    {
        return name_;
    }
    int GetAge() const
    {
        return age_;
    }
    std::string GetGender() const
    {
        return gender_;
    }

    void  SetName(std::string newName) 
    {
        name_ = newName;
    }
    void SetAge(int newAge) 
    {
        age_ = newAge;
    }
    void SetGender(std::string newGender) 
    {
        gender_ = newGender;
    }


    std::string Info()const 
    {
        std::string Info;
        Info = "Name: " + name_ + ", ", "Age: " + std::to_string(age_) + ", ","Gender: " + gender_ + ". ";
        return Info;
    
    
    }
private:
    std::string name_;
    std::string gender_;
    int age_;


};

//Связанные классы
//использование
//применение
//агрегация-способ связи классов в котором класс хранения не несёт ответственности за время жизни своего компонента
//композиция-тоже самое что и агрегация только уже НЕСЁТ ответственность и имеет общее время с компонентом
//

int main()
{
    Cat cat;
    std::cout << cat.Info();
}

