from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route("/", methods=['POST'])
def home():
    data = request.get_json()
    question = data.get('question', '')
    response = {
        'result': answer(question)
    }
    return jsonify(response)

def answer(question):
    return f"You entered: {question}"

if __name__ == "__main__":
    app.run(debug=True)
    
    
