from flask import Flask, render_template, request, jsonify
import ctypes
import os

#Loading my compiled C++ lib
lib = ctypes.CDLL(os.path.abspath("libpwanalyzer.so"))
lib.check_pw_valid.argtypes = [ctypes.c_char_p]
lib.check_pw_valid.restype = ctypes.c_bool
lib.pw_strength_score.argtypes = [ctypes.c_char_p]
lib.pw_strength_score.restype = ctypes.c_int

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/analyze', methods = ['POST'])
def analyze():
    data = request.get_json()
    pw = data.get('password', '').encode('utf-8')

    valid = lib.check_pw_valid(pw)
    score = lib.pw_strength_score(pw)

    return jsonify({
        "valid":valid, "score": score
    })

if __name__ == "__main__":
    app.run(debug = True) 
