import requests
import json

url = 'http://127.0.0.1:5000/api'
headers = {'Content-Type': 'application/json'}
data = {'param1': 'value1', 'param2': 'value2'}

response = requests.post(url, headers=headers, data=json.dumps(data))

if response.status_code == 200:
    print('POST request successful')
    print(response.json())
else:
    print('POST request failed')
    print('Status code:', response.status_code)