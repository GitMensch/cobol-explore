       identification division.
       program-id. game.

       data division.
       working-storage section.
       copy sdl.
       copy game-control-data.
       copy game-option-data.
       copy game-resource-data.

       procedure division.
       main.
           perform init
           perform until done
               perform poll-events
               perform process-control
               perform render
               perform end-step
           end-perform
           perform dispose
           goback
           .
       dispose.
           call 'sdlDestroyRenderer' using by value renderer
           call 'sdlDestroyWindow' using by value win
           call 'sdlQuit'
           .
       copy game-collision.
       copy game-control.
       copy game-event.
       copy game-option.
       copy game-render.
       copy game-resource.
       copy game-stat.
       copy game-tile.
       end program game.

       copy game-util.
