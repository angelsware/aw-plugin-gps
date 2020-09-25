import CoreLocation

class GpsSensor: NSObject, CLLocationManagerDelegate {
    private var listeners: Set<Int64> = Set()
    private var locationManager: CLLocationManager?
    private var requestingUpdates = false
    
    func addListener(listener: Int64) {
        listeners.insert(listener)
    }

    func removeListener(listener: Int64) {
        listeners.remove(listener)
    }

    func clearAllListeners() {
        listeners.removeAll()
    }

    func onCreate() {
        locationManager = CLLocationManager()
        locationManager?.delegate = self
    }

    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        listeners.forEach { listener in
            switch (status) {
            case .authorizedAlways, .authorizedWhenInUse:
                GpsDelegate.onRequestGpsPermissionResult(listener, granted: true)
                break
            default:
               GpsDelegate.onRequestGpsPermissionResult(listener, granted: false)
                break
            }
        }
    }
    
    func hasPermission() -> Bool {
        if CLLocationManager.locationServicesEnabled() {
            switch CLLocationManager.authorizationStatus() {
            case .notDetermined, .restricted, .denied:
                return false
            case .authorizedAlways, .authorizedWhenInUse:
                return true
            }
        }
        return false
    }

    func shouldShowRequestPermissionRationale() -> Bool {
        return false
    }

    func requestPermission() {
        locationManager?.requestAlwaysAuthorization()
    }

    func requestUpdates() {
        locationManager?.startUpdatingLocation()
        requestingUpdates = true
    }

    func removeUpdates() {
        locationManager?.stopUpdatingLocation()
        requestingUpdates = false
    }

    func onResume() {
        if (requestingUpdates) {
            requestUpdates()
        }
    }

    func onStop() {
        removeUpdates()
    }
    
    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        if let currentLocation = locations.last {
            listeners.forEach { listener in
                GpsDelegate.onGpsLocation(listener, latitude: currentLocation.coordinate.latitude, longitude: currentLocation.coordinate.longitude, timeSinceLastUpdate: 0, accuracy: Float(currentLocation.verticalAccuracy))
            }
        }
    }
}

@_cdecl("GpsSensor_create")
func GpsSensor_create() -> UnsafeMutablePointer<GpsSensor> {
    let sensor = UnsafeMutablePointer<GpsSensor>.allocate(capacity: 1)
    sensor.initialize(to: GpsSensor())
    return sensor
}

@_cdecl("GpsSensor_destroy")
func GpsSensor_destroy(ptr: UnsafeMutablePointer<GpsSensor>) {
	ptr.deallocate()
}

@_cdecl("GpsSensor_onCreate")
func GpsSensor_onCreate(ptr: UnsafeMutablePointer<GpsSensor>) {
    ptr.pointee.onCreate()
}

@_cdecl("GpsSensor_onResume")
func GpsSensor_onResume(ptr: UnsafeMutablePointer<GpsSensor>) {
    ptr.pointee.onResume()
}

@_cdecl("GpsSensor_onStop")
func GpsSensor_onStop(ptr: UnsafeMutablePointer<GpsSensor>) {
    ptr.pointee.onStop()
}

@_cdecl("GpsSensor_addListener")
func GpsSensor_addListener(ptr: UnsafeMutablePointer<GpsSensor>, listener: Int64) {
    ptr.pointee.addListener(listener: listener)
}

@_cdecl("GpsSensor_removeListener")
func GpsSensor_removeListener(ptr: UnsafeMutablePointer<GpsSensor>, listener: Int64) {
    ptr.pointee.removeListener(listener: listener)
}

@_cdecl("GpsSensor_clearAllListeners")
func GpsSensor_clearAllListeners(ptr: UnsafeMutablePointer<GpsSensor>) {
    ptr.pointee.clearAllListeners()
}

@_cdecl("GpsSensor_hasPermission")
func GpsSensor_hasPermission(ptr: UnsafeMutablePointer<GpsSensor>) -> Bool {
    return ptr.pointee.hasPermission()
}

@_cdecl("GpsSensor_shouldShowPermissionDescription")
func GpsSensor_shouldShowPermissionDescription(ptr: UnsafeMutablePointer<GpsSensor>)-> Bool {
    return ptr.pointee.shouldShowRequestPermissionRationale()
}

@_cdecl("GpsSensor_requestPermission")
func GpsSensor_requestPermission(ptr: UnsafeMutablePointer<GpsSensor>) {
    ptr.pointee.requestPermission()
}

@_cdecl("GpsSensor_requestUpdates")
func GpsSensor_requestUpdates(ptr: UnsafeMutablePointer<GpsSensor>) {
    ptr.pointee.requestUpdates()
}

@_cdecl("GpsSensor_removeUpdates")
func GpsSensor_removeUpdates(ptr: UnsafeMutablePointer<GpsSensor>) {
    ptr.pointee.removeUpdates()
}
