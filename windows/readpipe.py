import time
import sys
import win32pipe, win32file, pywintypes

# https://stackoverflow.com/questions/48542644/python-and-windows-named-pipes

a0c = "A0C32A42-313F-4BE8-9D25-106CF8767891"
a0c1 = "A0C32A42-313F-4BE8-9D25-106CF87678911"


def pipe_server(p):
    print("pipe server")
    count = 0
    pipe = win32pipe.CreateNamedPipe(
        f'\\\\.\\pipe\\{p}', win32pipe.PIPE_ACCESS_DUPLEX,
        win32pipe.PIPE_TYPE_MESSAGE | win32pipe.PIPE_READMODE_MESSAGE
        | win32pipe.PIPE_WAIT, 1, 65536, 65536, 0, None)
    try:
        print("waiting for client")
        win32pipe.ConnectNamedPipe(pipe, None)
        print("got client")

        while count < 10:
            print(f"writing message {count}")
            # convert to bytes
            some_data = str.encode(f"{count}")
            win32file.WriteFile(pipe, some_data)
            time.sleep(1)
            count += 1

        print("finished now")
    finally:
        win32file.CloseHandle(pipe)


def pipe_client(pipe):
    print("pipe client")
    quit = False

    print(pipe)

    while not quit:
        try:
            handle = win32file.CreateFile(
                f'\\\\.\\{pipe}',
                win32file.GENERIC_READ | win32file.GENERIC_WRITE, 0, None,
                win32file.OPEN_EXISTING, 0, None)
            res = win32pipe.SetNamedPipeHandleState(
                handle, win32pipe.PIPE_READMODE_MESSAGE, None, None)
            if res == 0:
                print(f"SetNamedPipeHandleState return code: {res}")
            while True:
                resp = win32file.ReadFile(handle, 64 * 1024)
                print(f"message: {resp}")
        except pywintypes.error as e:
            if e.args[0] == 2:
                print("no pipe, trying again in a sec")
                time.sleep(1)
            elif e.args[0] == 109:
                print("broken pipe, bye bye")
                # quit = True


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("need s or c as argument")
    elif sys.argv[1] == "s":
        pipe_server(sys.argv[2])
    elif sys.argv[1] == "c":
        pipe_client(sys.argv[2])
    else:
        print(f"no can do: {sys.argv[1]}")