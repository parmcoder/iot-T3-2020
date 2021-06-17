from flask import Flask, request
import json
app = Flask(__name__)

@app.route('/', methods=['POST'])
def root():
    data = json.loads(request.data)
    print(data)
    return 'OK'

app.run(host="0.0.0.0")
