# Win 32 demo mode

Makes simulator window titeless and borderless
To use with space bar as trigger use this snippet:

```lua
Runtime:addEventListener( "key", function(event)
	if event.keyName == "space" and event.phase == "down" then
		require("plugin.simDemoMode").init()
	end
end )
```

`build.setttings` example
```lua
settings = 
{
	plugins = 
	{
		"plugin.simDemoMode" = { publisherId="com.solar2d" },
	}
}
```