import asyncio

start_index = 0

async def print_num():
    global start_index
    if start_index > 5:
        print(f"start_index = {start_index}")
        start_index = 0  # 重置 start_index

async def test():
    while True:
        await print_num()
        start_index_jiajia()

def start_index_jiajia():
    global start_index
    start_index += 1
    print(f"now start_index is {start_index}")

async def main():
    task1 = asyncio.create_task(test())


if __name__ == "__main__":
    asyncio.run(main())
