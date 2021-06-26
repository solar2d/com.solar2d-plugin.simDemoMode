Runtime:addEventListener( "key", function(event)
	if event.keyName == "space" and event.phase == "down" then
		require("plugin.simDemoMode").init()
	end
end )


local icon = display.newImage("Icon.png")
transition.to(icon, {x=display.contentWidth, y=display.contentHeight, iterations=0, time=5000})