package com.angelsware.gps;

import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

import android.Manifest;
import android.content.Context;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.Bundle;
import androidx.core.content.ContextCompat;
import android.content.pm.PackageManager;
import android.util.Log;

import com.angelsware.engine.AppActivity;

public class Sensor {
	public static native void onGpsLocation(double latitude, double longitude, long timeSinceLastUpdate, long listener);
	public static native void onRequestGpsPermissionResult(boolean granted, long listener);

	private static String TAG = "aw";

	private static List sListeners = new ArrayList();
	private static double sLatitude = 0;
	private static double sLongitude = 0;
	private static long sLastUpdate = System.currentTimeMillis();
	private static boolean sRequestingUpdates = false;
	private static long sMinTime = 0;
	private static float sMinDistance = 0;

	private static LocationManager sLocationManager;
	private static final LocationListener sListener = new LocationListener() {
		@Override
		public void onStatusChanged(String provider, int status, Bundle extras) {
		}

		@Override
		public void onProviderEnabled(String provider) {
		}

		@Override
		public void onProviderDisabled(String provider) {
		}

		@Override
		public void onLocationChanged(Location location) {
			if (location != null) {
				long currentTime = System.currentTimeMillis();
				long timeSinceLastUpdate = currentTime - sLastUpdate;
				sLastUpdate = currentTime;
				sLatitude = location.getLatitude();
				sLongitude = location.getLongitude();
				for (Iterator<Long> i = sListeners.iterator(); i.hasNext();) {
					Long listener = i.next();
					onGpsLocation(sLatitude, sLongitude, timeSinceLastUpdate, listener);
				}
			}
		}
	};

	public static void addListener(long listener) {
		sListeners.add(listener);
	}

	public static void removeListener(long listener) {
		sListeners.remove(listener);
	}

	public static void clearAllListeners() {
		sListeners.clear();
	}

	public static void onCreate() {
		sLocationManager = (LocationManager)(AppActivity.getActivity().getSystemService(Context.LOCATION_SERVICE));
	}

	public static boolean hasPermission() {
		return ContextCompat.checkSelfPermission(AppActivity.getActivity(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED;
	}

	public static boolean shouldShowRequestPermissionRationale() {
		return AppActivity.getActivity().shouldShowRequestPermissionRationale(Manifest.permission.ACCESS_FINE_LOCATION);
	}

	public static void requestPermission() {
		if (ContextCompat.checkSelfPermission(AppActivity.getActivity(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_DENIED) {
			Log.d(TAG, "requesting missing gps permission");
			AppActivity.getActivity().requestPermissions(new String[] {Manifest.permission.ACCESS_FINE_LOCATION, Manifest.permission.ACCESS_BACKGROUND_LOCATION}, 2);
		} else {
			Log.w(TAG, "requesting already gotten gps permission");
		}
	}

	public static void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
		if (permissions.length > 0) {
			for (Iterator<Long> i = sListeners.iterator(); i.hasNext();) {
				Long listener = i.next();
				onRequestGpsPermissionResult(grantResults[0] == PackageManager.PERMISSION_GRANTED, listener);
			}
		}
	}

	public static void requestUpdates(final long minTime, final float minDistance) {
		if (!sRequestingUpdates) {
			AppActivity.getActivity().runOnUiThread(new Runnable() {
				public void run() {
					if (ContextCompat.checkSelfPermission(AppActivity.getActivity(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED) {
						Log.d(TAG, "requesting gps updates");
						sRequestingUpdates = true;
						sMinTime = minTime;
						sMinDistance = minDistance;
						Location location = sLocationManager.getLastKnownLocation(LocationManager.GPS_PROVIDER);
						sListener.onLocationChanged(location);
						sLocationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, minTime, minDistance, sListener);
					} else {
						Log.w(TAG, "requesting gps updates without permission");
					}
				}
			});
		}
	}

	public static void removeUpdates() {
		Log.w(TAG, "stop receiving gps updates");
		sLocationManager.removeUpdates(sListener);
	}

	public static void onResume() {
		if (sRequestingUpdates) {
			Log.d(TAG, "resuming gps updates");
			requestUpdates(sMinTime, sMinDistance);
		}
	}

	public static void onStop() {
		removeUpdates();
	}
}
