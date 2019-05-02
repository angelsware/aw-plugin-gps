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
Compass::ISensor* compassSensor = Compass::CSensorFactory::create();
compassSensor->onCreate();
compassSensor->addListener(this);

```

