%%
%% language: Erlang 4.7.3
%% author:   Michael Neumann
%% file:     test.erl
%%

-module(test).
-export([main/1]).

main(0) -> [];
main(N) -> main(N-1), io:fwrite("~w ",[N*N]).

%% Eingabemodus:
c("test.erl").   %% lädt test.erl
test:main(10).
 