from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=['GET', 'POST'])
def home():
    if request.method == 'POST':
        user_input = request.form['user_input']
        processed_result = process_user_input(user_input)
        return render_template("home.html", result=processed_result)

    return render_template("home.html")

def process_user_input(user_input):
    return f"You entered: {user_input}"

if __name__ == "__main__":
    app.run(debug=True)