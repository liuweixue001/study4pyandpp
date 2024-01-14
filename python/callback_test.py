class TestCallBackClass():
    def __init__(self):
        pass
    
    def __call__(self, string):
        print(f"hello callback in string")
        
def TestCallBackFunc(string):
    print(f"hello callback in {string}")
        
def test(string, callbackfunc):
    callbackfunc(string)
    


if __name__ == "__main__":
    m_callbackclass = TestCallBackClass()
    string = "class"
    test(string, m_callbackclass)
    string = "func"
    test(string, TestCallBackFunc)