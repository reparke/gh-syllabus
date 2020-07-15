---
title: Assignments
layout: category
category: assignments
classes: wide

---


<ul>
{% assign syllabus = (site.assignments | sort: "number") %}
{% for week in syllabus %}
  <li>
  	<a href="{{ site.baseurl }}{{ week.url }}">{{ week.title }}</a> 
  	(Due: <b>{{ week.date_due }}</b>)</li>
{% endfor %}
</ul>





