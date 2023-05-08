from flask import Flask, request

app = Flask(__name__)
str=""

@app.route('/api', methods=['POST'])
def process_post_request():
    data = request.get_json()
    # Process the data here
    # ...
    str=data
    print(str)


    return 'POST request processed successfully'

if __name__== "__main__":
    app.run()