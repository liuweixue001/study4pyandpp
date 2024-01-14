from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

@app.route("/", methods=['GET', 'POST'])
def home():
    if request.method == 'POST':
        data = request.get_json()
        user_input = data['user_input']
        processed_result = process_user_input(user_input)
        return jsonify({'result': processed_result})

    return render_template("home_json.html")

def process_user_input(user_input):
    # 在这里处理用户输入，这里只是一个简单的示例
    return f"You entered: {user_input}"

if __name__ == "__main__":
    app.run(debug=True)
