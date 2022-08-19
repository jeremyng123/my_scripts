import os
from pathlib import Path
from dotenv import load_dotenv

# Get the base directory
basepath = Path()
basedir = str(basepath.cwd())
# Load the environment variables
envars = basepath.cwd() / '..' / '.env'
load_dotenv(envars)
# Read an environment variable.
key = os.getenv('VT_API_KEY')
