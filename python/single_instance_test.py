import threading


class Test():
    _instance = None
    _name = ""
    def __init__(self):
        self.name = Test._name

    @classmethod
    def get_instance(cls):
        if cls._instance == None:
            print("初始化")
            cls._instance = Test()
        else:
            print("已初始化")
        return cls._instance
    
    def query_from_doc(self):
        return ['test1', "test2", "test3"]


class Singleton(object):
    _instance_lock = threading.Lock()

    def __new__(cls, *args, **kwargs):
        if not hasattr(Singleton, "_instance"):
            with Singleton._instance_lock:
                if not hasattr(Singleton, "_instance"):
                    Singleton._instance = object.__new__(cls)  
        return Singleton._instance
    
    def __init__(self):
        pass



        

if __name__ == "__main__":
    # Test._name = "test_instance"
    # a = Test.get_instance()
    # b = Test.get_instance()
    
    # print(a.name)
    
    # del Test
    
    obj1 = Singleton()
    obj2 = Singleton()
    print(obj1,obj2)

    def task(arg):
        obj = Singleton()
        print(obj)

    for i in range(10):
        t = threading.Thread(target=task,args=[i,])
        t.start()

    