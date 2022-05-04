Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp

셸 명령을 실행하는 것처럼 동작하는 프로그램 쓰기
- 실행할 명령줄은 이 프로그램의 인수가 됩니다.

- 실행 파일의 경로는 절대 또는 상대적이지만 프로그램이 경로를 작성하면 안 됩니다(예: PATH 변수).

- bash에서처럼 "|"과 ";"를 구현해야 합니다.

- "|" 바로 뒤에 또는 그 앞에 아무것도 붙이지 않거나 "|" 또는 ";"를 시도하지 않습니다.

- 프로그램은 경로만 인수로 사용하여 기본 제공 명령 CD를 구현해야 합니다('-' 없음 또는 매개 변수 없음).

- cd에 잘못된 인수 수가 있는 경우 프로그램이 STDERR "error: cd: bad arguments" 뒤에 '\n'을 출력해야 합니다.

- cd가 실패한 경우 프로그램은 STDERR "error: cd: cannot change to path_to_change"에 출력해야 합니다. 그 다음 path_to_change가 cd 인수로 대체된 '\n'입니다.

- cd 명령은 "|" 바로 뒤에 오거나 앞에 오지는 않습니다.

- 와일드카드(*, ~ 등)를 관리할 필요가 없습니다.)

- 환경 변수($BLA...)를 관리할 필요가 없습니다.

- exec과 chdir를 제외한 시스템 호출이 오류를 반환하는 경우 프로그램이 즉시 STDERR에 "error: fatal"을 출력하고 "\n"을 출력해야 하며 프로그램이 종료되어야 합니다.

- execeive에 실패한 경우 STDERR에서 "error: cannot execute executable_that_failed"를 출력한 후 executable_failed가 실패한 실행 파일의 경로로 대체됩니다(exece의 첫 번째 인수여야 함).

- 열려 있는 파일 수를 30개 미만으로 제한하더라도 프로그램이 수백 개 이상의 "|"을 관리할 수 있어야 합니다.

for example this should work:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

$>./microshell /bin/echo WOOT "; /bin/echo NOPE;" "; ;" ";" /bin/echo YEAH
WOOT ; /bin/echo NOPE; ; ;
YEAH
$>

Hints:
Don't forget to pass the environment variable to execve

Hints:
Do not leak file descriptors!