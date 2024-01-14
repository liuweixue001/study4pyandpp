import time 

def test():
    print("profile test")
    time.sleep(10)

test()

# use python -m cProfile profile_test.py
# or use python -m timeit '[i for i in range(100)]' for simple code