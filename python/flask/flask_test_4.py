import requests

url = "http://127.0.0.1:5000"
data = {"question": "What is the answer?"}

response = requests.post(url, json=data)