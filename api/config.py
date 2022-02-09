from dotenv import dotenv_values

config = dotenv_values(".env")
API_KEY = config['API_KEY']
MAX_BAR = 30
