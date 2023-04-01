       init.
           perform init-random
           perform init-sdl
           perform init-texture
           perform init-rect
           perform init-stats
           .

       init-reset.
           perform init-rect
           perform init-stats
           .

       init-random.
           move function numval(function current-date(1:16)) to seed
           move function abs(seed) to seed
           move function random(seed) to random-value
           .

       init-sdl.
           call 'SDL_Init' using by value sdl-init-video
           call 'SDL_CreateWindow' using
              by content z'Fall Fast'
              by value 100 0 win-w win-h 0
              returning win
           end-call
           call 'SDL_CreateRenderer' using
               by value win
      *        -- TODO How to pass a null pointer? --
               by reference null
               by value sdl-renderer-accelerated
               returning renderer
           end-call
           call 'SDL_SetRenderDrawBlendMode' using
               by value renderer 1
           end-call
           .

       init-texture.
      *    call 'load-texture' using
      *        z'assets/font.png' renderer font-texture
      *    end-call
           call 'loadTextureData' using
               by value renderer
               by reference font-asset-data
               by value font-asset-data-size
               returning font-texture
           end-call
      *    call 'load-texture-data' using
      *        ground-asset-data ground-asset-data-size renderer
      *        ground-texture
      *    end-call
           call 'loadTextureData' using
               by value renderer
               by reference ground-asset-data
               by value ground-asset-data-size
               returning ground-texture
           end-call
           call 'loadTextureData' using
               by value renderer
               by reference menu-asset-data
               by value menu-asset-data-size
               returning menu-texture
           end-call
           call 'loadTextureData' using
               by value renderer
               by reference player-asset-data
               by value player-asset-data-size
               returning player-texture
           end-call
           call 'loadTextureData' using
               by value renderer
               by reference wall-asset-data
               by value wall-asset-data-size
               returning wall-texture
           end-call
           .

       init-rect.
           move zero to ground-row-index
           compute ground-src-rect-x = 4 * tile-size
           compute ground-src-rect-y = 4 * tile-size
           call 'SDL_QueryTexture' using
               by value menu-texture
               by reference null null menu-src-rect-w menu-src-rect-h
           end-call
           move zero to menu-src-rect-x menu-src-rect-y
           move menu-src-rect-w to menu-dst-rect-w
           move menu-src-rect-h to menu-dst-rect-h
           compute menu-dst-rect-x = (win-w - menu-dst-rect-w) / 2
           compute menu-dst-rect-y = (win-h - menu-dst-rect-h) / 2
           move tile-size to
               ground-src-rect-w ground-src-rect-h
               ground-dst-rect-w ground-dst-rect-h
           move 96 to player-src-rect-w player-dst-rect-w
           move 128 to player-src-rect-h player-dst-rect-h
           compute player-src-rect-x = 8 * player-src-rect-w
           compute player-dst-rect-x = (game-w - player-src-rect-w) / 2
           compute player-dst-rect-y = 4 * tile-size - player-src-rect-h
           .

       init-stats.
           move zeros to distance decimal-time score
           set mode-init to true
           set step-frame-fall to true
           .
