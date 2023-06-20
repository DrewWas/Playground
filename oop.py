# Practice, we talkin bout Practice 

class ISIS:
    def __init__(self, name, age):
        self.name = name
        self.age = age


    def add_one(self, x):
        self.x = 4
        return 1 + x
    
    def get_name(self):
        return self.name
    
    def get_age(self):
        return self.age
    
    def set_age(self, age):
        self.age = age
        
    def bark(self):
        print("bark")


A = ISIS("Joe", 51)
B = ISIS("Harem", 49)

A.set_age(100)



class Student:
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade # 0 - 100
        print("Created " + str(self.name))

        
    def get_grade(self):
        return self.grade




class Course:
    def __init__(self, name, max_students):
        self.name = name
        self.max_students = max_students
        self.students = []

    def add_student(self, student):
        if len(self.students) < self.max_students:
            self.students.append(student)
            return True
        return False

    def get_students(self):
        return [self.students[i].name for i in range(len(self.students))]
    
    def get_avg_grade(self):
        return sum([self.students[i].get_grade() for i in range(len(self.students))]) / len(self.students)
    

    


John = Student("John", 12, 87)
Sera = Student("Sera", 12, 89)
James = Student("James", 12, 98)

Math = Course("Math1B", 3)

Math.add_student(John)
Math.add_student(Sera)
Math.add_student(James)






class Cat:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        self.hungry = True
        print("created")

    def speak(self):
        print("Meow")

    def eat(self):
        self.hungry = False

    def is_hungry(self):
        return self.hungry

"""
class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        self.hungry = True

    def speak(self):
        print("Bark")

    def eat(self):
        self.hungry = False

    def is_hungry(self):
        return self.hungry
"""

class Dog(Cat):
    def speak(self):
        print("Bark")

Buster = Dog("Buster", 1)
Earl = Cat("Earl", 13)

Buster.eat()
Earl.speak()
Buster.speak()
print(Buster.is_hungry())










