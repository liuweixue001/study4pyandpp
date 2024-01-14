
class B():
    def __init__(self, name):
        self.name = A(name)


class A():
    def __init__(self, name):
        self.name = "form A name is " + name
    
        
if __name__ == "__main__":
    b = B("test")
    print(b.name.name)