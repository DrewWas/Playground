# Practice, we talkin bout Practice 

class ISIS:
    def __init__(self, name, age):
        self.inshalla = name
        self.harem = age


    def add_one(self, x):
        self.x = 4
        return 1 + x
    
    def get_name(self):
        return self.inshalla
    
    def get_age(self):
        return self.harem
    
    def set_age(self, age):
        self.harem = age
        
        

    def bark(self):
        print("bark")


A = ISIS("Joe", 51)
B = ISIS("Harem", 49)

print(A.harem)

A.set_age(100)

print(A.harem)
