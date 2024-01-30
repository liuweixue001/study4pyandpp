class Person:
    def __init__(self, name: str = None, age: int = None):
        self.name = name
        self.age = age
    
    def rename(self, newName):
        self.name = newName

class Test:
    def __init__(self, person):
        self.person = person

person = Person(name = "hello", age = 18)
test = Test(person)
print(f"before test.person.name = {test.person.name}")
test.person.rename("hi")
print(f"after test.person.name = {test.person.name}")