# aw-plugin-gps

GPS plugin for Angels' Ware rendering engine.

### Getting Started

Add the **plugins** section to the **config.json** file of your project.

```
{
	...

	"plugins":[
		{
			"repo":"https://github.com/angelsware/aw-plugin-gps.git",
			"tag":"*"
		}
	]
}
```

```
Gps::ISensor* gpsSensor = Gps::CSensorFactory::create();
gpsSensor->onCreate();
gpsSensor->addListener(this);

```
